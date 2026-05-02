// Function : FUN_40185450
// Address  : 0x40185450
// Size     : 50 bytes


bool FUN_40185450(int param_1)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (*(int *)(param_1 + 200) != 0)) {
    cVar1 = *(char *)(*(int *)(param_1 + 200) + 5);
    bVar2 = cVar1 == '\n' || (byte)(cVar1 - 4U) < 2;
  }
  return bVar2;
}

