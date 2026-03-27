# 📝 Python RESTful Blog API

A simple RESTful Blog API built with Flask that supports full CRUD operations (Create, Read, Update, Delete) for blog posts.

---

## 🚀 Features

* Create blog posts
* Retrieve all posts
* Retrieve a single post by ID
* Update a post
* Delete a post
* In-memory storage (no database required)

---

## 🛠️ Tech Stack

* **Language:** Python
* **Framework:** Flask

---

## 📦 Installation

### 1. Clone the repository

```bash
git clone https://github.com/mi8taw/blog.git
cd python-blog-api
```

---

### 2. Create virtual environment (optional but recommended)

```bash
python -m venv venv
source venv/bin/activate   # On Linux/macOS
venv\Scripts\activate      # On Windows
```

---

### 3. Install dependencies

```bash
pip install flask
```

---

## ▶️ Run the Server

```bash
python app.py
```

Server will start at:

```
http://127.0.0.1:5000
```

---

## 📡 API Endpoints

### ➕ Create Post

```http
POST /posts
```

**Request Body**

```json
{
  "title": "My Post",
  "content": "This is the content"
}
```

---

### 📄 Get All Posts

```http
GET /posts
```

---

### 🔍 Get Post by ID

```http
GET /posts/{id}
```

---

### ✏️ Update Post

```http
PUT /posts/{id}
```

**Request Body**

```json
{
  "title": "Updated title",
  "content": "Updated content"
}
```

---

### ❌ Delete Post

```http
DELETE /posts/{id}
```

---

## 🧪 Testing with curl

### Create a post

```bash
curl -X POST http://127.0.0.1:5000/posts \
-H "Content-Type: application/json" \
-d '{"title":"Hello","content":"World"}'
```

---

### Get all posts

```bash
curl http://127.0.0.1:5000/posts
```

---

### Get a single post

```bash
curl http://127.0.0.1:5000/posts/1
```

---

### Update a post

```bash
curl -X PUT http://127.0.0.1:5000/posts/1 \
-H "Content-Type: application/json" \
-d '{"title":"Updated"}'
```

---

### Delete a post

```bash
curl -X DELETE http://127.0.0.1:5000/posts/1
```

---

## ⚠️ Limitations

* No persistent storage (data is lost on restart)
* No authentication or authorization
* Minimal validation
* Not suitable for production use

---

## 💡 Future Improvements

* Add database integration (SQLite, PostgreSQL)
* Use an ORM like SQLAlchemy
* Add authentication (JWT)
* Add input validation
* Structure project into modules
* Dockerize the application

---

## 📄 License

This project is licensed under the MIT License.

---

## 🤝 Contributing

Contributions are welcome!
Feel free to fork the project and submit a pull request.

---

## 👨‍💻 Author

Your Name
GitHub: https://github.com/mi8taw

---
