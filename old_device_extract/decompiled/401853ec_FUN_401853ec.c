// Function : FUN_401853ec
// Address  : 0x401853ec
// Size     : 26 bytes


void FUN_401853ec(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = '\0';
  if (param_2 != 0) {
    cVar1 = *(char *)(param_2 + 0xee) + '\x01';
  }
  *(char *)(param_1 + 0x30) = cVar1;
  memw();
  memw();
  return;
}

