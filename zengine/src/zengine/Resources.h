//#include <iostream>
//#include <rend/rend.h>
namespace zengine {

    struct Resource;

    struct Resources
    {
        //lab 5
        template <typename T>
        std::shared_ptr<T> load(const std::string& _path)
        {

            // Search for previously loaded resource
            for (size_t i = 0; i < m_resources.size(); ++i)
            {
                // had to use dynamic pointer cast to make sure the base type is safely casted to the derived type
                if (m_resources.at(i)->getPath() == _path)
                {
                    return std::dynamic_pointer_cast<T>(m_resources.at(i)); 
                }
            }
           
          //  std::cout << "Loading resource: " << _path << std::endl;
            std::shared_ptr<T> rtn = std::make_shared<T>();
            rtn->m_path = _path;
			rtn->load();
            m_resources.push_back(rtn);
            return rtn;
        }

    private:
        std::vector<std::shared_ptr<Resource>> m_resources;
    };

}
