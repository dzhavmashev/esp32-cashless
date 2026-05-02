// Function : FUN_40185048
// Address  : 0x40185048
// Size     : 33 bytes


void FUN_40185048(int param_1,int param_2)

{
  char cVar1;
  
  do {
    param_2 = param_2 + -1;
    if (param_2 < 0) break;
    cVar1 = *(char *)(param_1 + param_2) + '\x01';
    *(char *)(param_1 + param_2) = cVar1;
    memw();
  } while (cVar1 == '\0');
  memw();
  return;
}

