def msg(act, name):
    if act == "Enter":
        return name+"님이 들어왔습니다."
    else:  # act == "Leave"
        return name+"님이 나갔습니다."


def solution(record):
    answer = []
    users = {}

    for r in record:
        splitRecord = r.split()
        command = splitRecord[0]
        userId = splitRecord[1]

        if command == "Leave":
            if userId in users:
                users[userId].append((command, ""))
            else:
                users[userId] = [(command, "")]
        else:
            if userId in users:
                users[userId].append((command, splitRecord[2]))
            else:
                users[userId] = [(command, splitRecord[2])]

    nicknames = {}

    for userId, action in users.items():
        for command, name in reversed(action):
            if command == "Enter" or command == "Change":
                nicknames[userId] = name
                break

    for output in record:
        splitOutput = output.split()
        if splitOutput[0] != "Change":
            answer.append(msg(splitOutput[0], nicknames[splitOutput[1]]))

    return answer