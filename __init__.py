#!/usr/bin/python3.5
import sys
sys.path.insert(0,"/var/www/PageHawk/pagehawk/")
print(sys.path)
from flask import Flask, jsonify, make_response, request, render_template
from flask_cors import CORS
from Lean_Parsev2 import LeanParse
from Text_Anna import Text_Anna
app = Flask(__name__)

@app.route('/', methods=['GET'])
def homepage():
    return render_template('index.html')

@app.route('/about', methods=['GET'])
def about():
    return render_template('about.html')

#Normal API reply
@app.route('/pagehawk', methods=['GET'])
def entry():

    reply = [
    {"word_count": 404, "sent_count": 404, "read_level": 404, "read_time" :404, "load_time": 404}, #Index 0,
    {"keyword_dense": ['UNABLE TO GET URL']},    #Index 1
    {"headings": ['UNABLE TO GET URL']}, #Index 2
    {"outbound_links": ['UNABLE TO GET URL']},    #Index 3
    {"summary": "UNABLE TO GET URL"}  #Index 4
    ]
    
    # Getting link from request
    page_url = request.args.get("link")

    # Loading link into object
    link_init = LeanParse(page_url)

    # Requesting content from URL
    page_content = link_init.content()
    
    if page_content != "UNABLE TO GET URL":
        loaded_text = Text_Anna(page_content["text"])

        reply[0]["load_time"] = str(page_content["load_time"])[:5] + "s"
        reply[0]["word_count"] = loaded_text.word_count()
        reply[0]["read_time"] = loaded_text.read_time()
        reply[0]["sent_count"] = loaded_text.sentence_count()
        reply[0]["read_level"] = loaded_text.reading_ease()
        reply[1]["keyword_dense"] = loaded_text.keyword_density()
        reply[2]["headings"] = page_content["headings"][:7]
        reply[3]["outbound_links"] = page_content["links"]
        reply[4]["summary"] = loaded_text.summary()

        return jsonify({"pagehawk_api": reply})
    else:
        return jsonify({"pagehawk_api": reply})

#Error Handling Unable to find endpoint
@app.errorhandler(404)
def not_found(error):
    return make_response(jsonify({"error": "Not Found"}), 404)

#Bad request form
@app.errorhandler(400)
def bad_request(error):
    return make_response(jsonify({"error": "Invalid Request"}, 400))
if __name__ == '__main__':
    CORS(app)
    app.run()
