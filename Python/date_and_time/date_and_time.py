import datetime

# calendar module can be used to print formatted calendar strings
# time module can be used similarly to the time.h library in C
# pytz package can be used for timezone support

now = datetime.datetime.now()
print("Current date and time:", now)
print("Current time with UTC difference:", now.astimezone())
print("Current date:", now.date())
print("Current year:", now.year)
print("Current month:", now.month)
print("Current day:", now.day)
print("Current hour:", now.hour)
print("Current minute:", now.minute)
print("Current second:", now.second)
print("Current microsecond:", now.microsecond)
print("Current time:", now.time())
print("Current timestamp (POSIX):", now.timestamp())
print("Current UTC date and time:", now.utcnow())
print("Current weekday:", now.weekday())

# formmatted date and time (many other format codes available)
print("\nCurrent formatted date and time:", now.strftime("%d/%m/%y, %I:%M:%S %p"))
print("Current formattted date:", now.strftime("Week of year: %W, Day of year: %j"))

# convert a string to a datetime object using format codes
date_string = "9:33:09-pm 29 Nov 1973"
print("\ndate_string:", date_string)
print("date_string as datetime object:", datetime.datetime.strptime(date_string, "%I:%M:%S-%p %d %b %Y"))

# datetime from timestamp
timestamp = 123456789
datetime_from_timestamp = datetime.datetime.fromtimestamp(timestamp)
date_from_timestamp = datetime.date.fromtimestamp(timestamp)
print(f"\nDate and time from timestamp {timestamp}: {datetime_from_timestamp}")
print(f"Date from timestamp {timestamp}: {date_from_timestamp}")

# timedeta objects and difference between times
difference = now - datetime_from_timestamp # difference is a timedelta object
print("\nDifference between now and timestamp: ", difference)
print("Days between now and timestamp: ", difference.days)
print("Seconds from time difference between now and timestamp: ", difference.seconds)
print("Microseconds from time difference between now and timestamp: ", difference.microseconds)
print("Total seconds between now and timestamp: ", difference.total_seconds())
