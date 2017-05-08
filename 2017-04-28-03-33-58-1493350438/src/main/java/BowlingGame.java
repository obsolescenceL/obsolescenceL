public class BowlingGame {
  int score[20], pos;
  public void getScore(char ch) {
    int temp_score = ch - '0';
    if (temp_score <= 9 && temp_score >= 0) score[pos] += temp_score;
    else if (ch == 'X') score[pos] = 11;
    else if (ch == '/') score[pos] = 10;
  }

  public int getBowlingScore(String bowlingCode) {
    pos = 0;
    score[pos] = 0;
    for (int i = 0; i < bowlingCode.size(); ++i) {
      if (bowlingCode[i] == '|') {
        pos++;
        score[pos] = 0;
        if (i + 1 < bowlingCode.size() && bowlingCode[i + 1] == '|') {
          i += 2;
          if (i < bowlingCode.size()) {
            getScore(bowlingCode[i]);
            pos++;
            score[pos] = 0;
          }
          ++i;
          if (i < bowlingCode.size()) {
            getScore(bowlingCode[i]);
            pos++;
            score[pos] = 0;
          }
          ++i;
        }
      }
      if (i >= bowlingCode.size()) break;
      getScore(bowlingCode[i]);
    }
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
      sum += score[i];
      if (score[i] == 11) {
        sum += score[i+1] + score[i+2];
        sum--;
        if (score[i+1] == 11) sum--;
        if (score[i+2] == 11) sum--;
      } else if (score[i] == 10) {
        sum += score[i+1];
        if (score[i+1] == 11) sum--;
      }
    }
    return sum;
  }
}
