// Function : FUN_400fd498
// Address  : 0x400fd498
// Size     : 20 bytes


void FUN_400fd498(char *param_1)

{
  while( true ) {
    if (*param_1 == '\0') break;
    FUN_400fd40c();
    param_1 = param_1 + 1;
  }
  return;
}

