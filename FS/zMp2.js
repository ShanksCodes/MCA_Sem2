
const mongoose = require('mongoose');
mongoose.set('strictQuery', true);  //added to prevent deprecation warning

// Define a schema for your data
const userSchema = new mongoose.Schema({
  name: String,
  email: String,
  password: String,
});

// Create a model for your data
const User = mongoose.model('User', userSchema);

// Connect to the database and insert some data
mongoose
  .connect('mongodb://localhost:27017/testingdb')
  .then(() => {
    const newUser = new User({
      name: 'John Doe',
      email: 'johndoe@example.com',
      password: 'password123',
    });

    return newUser.save();
  })
  .then(() => console.log('Data inserted successfully'))
  .catch((err) => console.log(err));
