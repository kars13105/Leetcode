SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) as attended_exams
FROM students as s
cross join subjects as sub
left join examinations as e
on s.student_id = e.student_id AND sub.subject_name = e.subject_name
group by s.student_id, sub.subject_name, s.student_name
order by s.student_id, sub.subject_name;
