#include "WriteFile.h"
#include <fstream>
#include "../Exceptions/WrongNumberOfArguments.h"
#include "../Exceptions/FileOpeningFail.h"

namespace SimpleBlocks {
    static Common::BlockMaker<WriteFile> maker("writefile");
    
    std::list<std::string>
    WriteFile::execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
        if (args.empty()) {
            throw Exceptions::WrongNumberOfArguments("insufficient arguments for writefile");
        } else if (args.size() > 1) {
            throw Exceptions::WrongNumberOfArguments("too much arguments for writefile");
        }
    
        std::ofstream output(args[0], std::ofstream::trunc);
        if (!output) {
            throw Exceptions::FileOpeningFail("output file opening failed");
        }
    
        for (const auto& word : text) {
            output << word;
            if (word != "\n") {
                output << " ";
            }
        }
        
        std::list<std::string> newText;
        return newText;
    }
    
    Common::BlockType WriteFile::getType() {
        return Common::BlockType::OUT;
    }
}