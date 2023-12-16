#pragma once

#define FOREACH_VALID_LINE(contents, func) \
    int lineNumber = 0; \
    for (const std::string line: contents) { \
        if (line.length() == 0) continue; \
        lineNumber++; \
        func \
    }

#define VALIDATE_LINE(line) \
    lineNumber++; \
    if (line.length() == 0) continue; \

#define GET_FILE_ARRAY(testInput) \
    auto contents = fileManager->GetFileAsArray(_day, testInput); \
