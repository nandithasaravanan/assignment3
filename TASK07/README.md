Aim
To design and implement a C program that counts student council election votes, identifies invalid votes, sorts candidates according to their vote counts, and determines the winner or tie.
A. Problem Interpretation
Input:
- Number of candidates (maximum 12).
- Number of votes (maximum 5,000 for normal election operation).
- Candidate numbers entered by voters.
Output:
- Total valid votes.
- Total invalid votes.
- Votes received by each candidate.
- Candidates arranged in descending order of votes.
- Winner or tie announcement.
Validation rules:

A vote is invalid if:
- The vote is 0.
- The vote is negative.
- The vote is greater than the number of candidates.
B. Arrays Required
Array	Size	Purpose
votes[]	500000	Stores entered votes for performance testing
count[]	12	Stores votes received by each candidate
order[]	12	Stores candidate positions for sorting

The normal election limit is 5,000 votes. The larger array also supports the required 500,000-vote performance experiment.
C. Counting Method
A count array is used to record the votes.

For every valid vote, the corresponding candidate's count is increased by one.

For example:
Candidate	Votes
1	3
2	5
3	2
4	5

Invalid votes are counted separately.
D. Sorting Method
Selection sort is used to arrange candidates in descending order of votes.

The candidate with the highest vote count is placed first.

If two candidates have equal votes, their original candidate-number order is maintained.
E. Tie Detection
After sorting, the first candidate has the highest vote count.

If the second candidate has the same vote count as the first candidate, the election is declared a tie.
F. Pseudocode
START

Read number of candidates
Read number of votes

Initialize count array to zero
Set valid = 0 and invalid = 0

FOR each vote
    IF vote is between 1 and candidates
        Increase count[vote]
        Increase valid
    ELSE
        Increase invalid
    END IF
END FOR

Initialize candidate order array
