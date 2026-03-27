from flask import Flask, request, jsonify

app = Flask(__name__)

# In-memory storage
posts = []
next_id = 1

# CREATE post
@app.route('/posts', methods=['POST'])
def create_post():
    global next_id
    data = request.get_json()

    if not data or 'title' not in data or 'content' not in data:
        return jsonify({'error': 'Invalid input'}), 400

    post = {
        'id': next_id,
        'title': data['title'],
        'content': data['content']
    }

    posts.append(post)
    next_id += 1

    return jsonify(post), 201


# READ all posts
@app.route('/posts', methods=['GET'])
def get_posts():
    return jsonify(posts), 200


# READ one post
@app.route('/posts/<int:post_id>', methods=['GET'])
def get_post(post_id):
    post = next((p for p in posts if p['id'] == post_id), None)

    if not post:
        return jsonify({'error': 'Post not found'}), 404

    return jsonify(post), 200


# UPDATE post
@app.route('/posts/<int:post_id>', methods=['PUT'])
def update_post(post_id):
    data = request.get_json()
    post = next((p for p in posts if p['id'] == post_id), None)

    if not post:
        return jsonify({'error': 'Post not found'}), 404

    post['title'] = data.get('title', post['title'])
    post['content'] = data.get('content', post['content'])

    return jsonify(post), 200


# DELETE post
@app.route('/posts/<int:post_id>', methods=['DELETE'])
def delete_post(post_id):
    global posts
    post = next((p for p in posts if p['id'] == post_id), None)

    if not post:
        return jsonify({'error': 'Post not found'}), 404

    posts = [p for p in posts if p['id'] != post_id]

    return jsonify({'message': 'Post deleted'}), 200


if __name__ == '__main__':
    app.run(debug=True)
