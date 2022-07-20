import { useState,useEffect } from "react"
import React from 'react'
import axios from 'axios';

const CreateBlog = () => {

  const [blogdata , setblogdata] = useState({
    title: "",
    description: "",
    author: "",
    reading_time: ""
  })

  let name,value
  let baseURL = "https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs"
  
  const handleinput =(e)=>{
    console.log(e)
    name = e.target.name
    value = e.target.value
    setblogdata({...blogdata , [name]:value})

  }

  const submitButton = (e) =>{
  e.preventDefault()
    axios.post(
      baseURL,
      blogdata,
      {

          headers: {

              'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',

              'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'

          }

      }

  ).then(console.log("done"))
  setblogdata({
    title: "",
    description: "",
    author: "",
    reading_time: ""
  })

}

  return (
    <>


    <form className='container' style={{width:'20rem',marginTop:'10px',marginLeft:'10px'}}>
  <div className="mb-3">
    <label htmlFor="text"  className="form-label"><b>Title</b></label>
    <input type="text" name="title" className="form-control"  id="text" value={blogdata.title} onChange={handleinput}/>
  </div>
  <div className="mb-3">
    <label htmlFor="description"  className="form-label"><b>Description</b></label>
    <input type="text" name="description" className="form-control" id="description" value={blogdata.description} onChange={handleinput}/>
  </div>
  <div className="mb-3">
    <label className="form-label"><b>Author</b></label>
    <input type="text" name="author" className="form-control" id="author" value={blogdata.author} onChange={handleinput}/>
  </div>
  <div className="mb-3">
    <label htmlFor="reading_time"  className="form-label"><b>Reading_time</b></label>
    <input type="number" name="reading_time" className="form-control" id="reading_time" value={blogdata.reading_time} onChange={handleinput}/>
  </div>
  <button type="submit" className="btn btn-primary" onClick={submitButton}>Submit</button>
</form>
   
    
    </>
  )
}

export default CreateBlog