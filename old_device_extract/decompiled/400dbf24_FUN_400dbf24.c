// Function : FUN_400dbf24
// Address  : 0x400dbf24
// Size     : 26 bytes


bool FUN_400dbf24(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x20) != '\0') {
    iVar2 = FUN_400e90d8();
    bVar1 = iVar2 == 3;
  }
  return bVar1;
}

