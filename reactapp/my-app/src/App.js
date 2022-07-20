import './App.css';
import Blogs from './components/Blogs';
import CreateBlog from "./components/CreateBlogs";
import Navbar from './components/Navbar';
import { Routes, Route, Link } from "react-router-dom";

const App = () => {
  return (
    <>


    <Navbar/>

    <Routes>
        <Route path="/" element={<CreateBlog />} />
        <Route path="/blogs" element={<Blogs/>} />
    </Routes>
    
    
    </>
  );
}

export default App;
