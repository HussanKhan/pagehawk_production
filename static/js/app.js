var ViewModel = function(){
    self = this;
    //Upper sections views
    this.url = ko.observable();
    this.urlpassed = ko.observable(false);
    this.loading = ko.observable(false);
    this.showana = ko.observable(true);

    this.checklink = ko.observable();

    //Result section views
    this.word_count = ko.observable();
    this.sent_count = ko.observable();
    this.read_ease = ko.observable();
    this.read_time = ko.observable();
    this.load_time = ko.observable();
    this.keywords = ko.observableArray([
    ]);
    this.headings = ko.observableArray([]);
    this.olinks = ko.observableArray([]);
    this.summary = ko.observable();

    //fill keywords
    function fillkws(array) {
        for (var i = 0; i < array.length; i++) {
            self.keywords.push({word: array[i]});
        }
    };

    //Fill headings
    function fillhead(array) {
        for (var i = 0; i < array.length; i++) {
            self.headings.push({heading: array[i]});
        }
    };

    //Fill outbound links
    function fillolinks(array) {
        for (var i = 0; i < array.length; i++) {
            self.olinks.push({link: array[i]});
        }
    };

    //Clears search bar
    this.cleanbar = function() {
        if (this.url()) {
            this.url('');
        }
    }

    //Clicking button
    this.analyze = function() {
        if (this.url()) {
            this.urlpassed(true);
            this.showana(false);
            this.loading(true);

            $.ajax({
                url: "https://pagehawk.io/pagehawk?link=" + this.url(),
                dataType: 'json',
                success: function (data) {
                    //UPDATING VIEW
                    self.word_count(data.pagehawk_api[0].word_count);
                    self.sent_count(data.pagehawk_api[0].sent_count);
                    self.read_ease(data.pagehawk_api[0].read_level);
                    self.read_time(data.pagehawk_api[0].read_time);
                    self.load_time(data.pagehawk_api[0].load_time);
                    self.checklink(self.url());
                    //Updating Keywords
                    self.keywords.removeAll();
                    fillkws(data.pagehawk_api[1].keyword_dense);

                    //Updating Headings
                    self.headings.removeAll();
                    fillhead(data.pagehawk_api[2].headings);

                    //Updating outbound links
                    self.olinks.removeAll();
                    fillolinks(data.pagehawk_api[3].outbound_links);

                    //Updating Summary
                    self.summary(data.pagehawk_api[4].summary);

                    //Updating upper section
                    self.loading(false);
                    self.showana(true);
                },
                error: function (data) {
                    //Updating upper section
                    self.loading(false);
                    self.showana(true);
                }
            });
        } else {
            this.urlpassed(false);
        }
    };
};


ko.applyBindings(new ViewModel());
