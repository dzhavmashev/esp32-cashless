// Function : FUN_40183fb4
// Address  : 0x40183fb4
// Size     : 30 bytes


bool FUN_40183fb4(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0xa4) != '\0') {
    memw();
    bVar1 = *(int *)(param_1 + 0x28) == 2;
  }
  return bVar1;
}

