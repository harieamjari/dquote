extern void register_deadquote(void);

int main(){
  register_deadquote();
  int a = *((int*)0); /* BOOOM! */
}
