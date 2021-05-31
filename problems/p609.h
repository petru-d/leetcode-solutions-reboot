#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace p609
{
    class Solution
    {
      public:
        std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string>& paths)
        {
            // create a vector (tree in case of serious file system) of files
            // each file will contain only the indices where the data is located

            struct FileContentDescriptor
            {
                size_t IndexInPaths = -1;
                size_t StartPos = -1;
                size_t Size = -1;
            };

            struct FileInfo
            {
                std::string Path;
                FileContentDescriptor Contents;
            };

            std::vector<FileInfo> files;

            for (size_t i = 0; i < paths.size(); ++i)
            {
                const auto& p = paths[i];

                auto dirEnd = p.find(' ');
                auto currPos = dirEnd + 1;
                while (currPos != std::string::npos)
                {
                    auto fileNameEnd = p.find('(', currPos);

                    auto fileContentsEnd = p.find(')', fileNameEnd);

                    FileInfo info;
                    info.Path = p.substr(0, dirEnd) + "/" + p.substr(currPos, fileNameEnd - currPos);
                    info.Contents.IndexInPaths = i;
                    info.Contents.StartPos = fileNameEnd + 1;
                    info.Contents.Size = fileContentsEnd - fileNameEnd - 1;

                    files.push_back(std::move(info));

                    currPos = p.find(' ', fileContentsEnd);
                    if (currPos != std::string::npos)
                        ++currPos;
                }
            }

            // make a hashmap from file content hashes to a list of addresses in the vector (tree) of files
            std::unordered_map<size_t, std::vector<size_t>> content_hashes;
            for (size_t i = 0; i < files.size(); ++i)
            {
                const auto& f = files[i];
                const auto& cont = f.Contents;
                auto h = std::hash<std::string>{}(paths[cont.IndexInPaths].substr(cont.StartPos, cont.Size));
                content_hashes[h].push_back(i);
            }

            // if there are multiple files with the same hash, create a list of lists,
            // each sub-list will contain files with the same content (check by data)

            auto equal_contents = [&](size_t i, size_t j) {
                const auto& fi = files[i];
                const auto& fj = files[j];
                if (fi.Contents.Size != fj.Contents.Size)
                    return false;

                for (auto x = 0; x < fi.Contents.Size; ++x)
                {
                    if (paths[fi.Contents.IndexInPaths][fi.Contents.StartPos + x] !=
                        paths[fj.Contents.IndexInPaths][fj.Contents.StartPos + x])
                        return false;
                }
                return true;
            };

            std::vector<std::vector<std::string>> duplicates;

            for (const auto& [k, v] : content_hashes)
            {
                const auto& filesWithSameHash = v;
                if (filesWithSameHash.size() <= 1)
                    continue;

                std::vector<std::vector<size_t>> filesWithSameContent = {{v[0]}};

                // for each file with the same hash, check if it fits (by content) in one of the buckets
                for (size_t i = 1; i < filesWithSameHash.size(); ++i)
                {
                    bool found = false;
                    for (size_t j = 0; j < filesWithSameContent.size(); ++j)
                        if (equal_contents(filesWithSameHash[i], filesWithSameContent[j][0]))
                        {
                            filesWithSameContent[j].push_back(filesWithSameHash[i]);
                            found = true;
                            break;
                        }
                    if (!found)
                        filesWithSameContent.push_back({filesWithSameHash[i]});
                }

                for (const auto& group : filesWithSameContent)
                {
                    if (group.size() <= 1)
                        continue;

                    std::vector<std::string> groupDuplicates;
                    for (const auto& g : group)
                        groupDuplicates.push_back(files[g].Path);

                    duplicates.push_back(std::move(groupDuplicates));
                }
            }

            return duplicates;
        }
    };
}
