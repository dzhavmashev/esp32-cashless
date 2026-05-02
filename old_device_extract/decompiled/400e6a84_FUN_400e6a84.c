// Function : FUN_400e6a84
// Address  : 0x400e6a84
// Size     : 47 bytes


byte FUN_400e6a84(int param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_400da468(param_1 + 8);
  if (iVar2 == 0) {
    iVar2 = FUN_400da468(param_1 + 0x18);
    bVar1 = 0;
    if (iVar2 == 0) {
      bVar1 = FUN_400da468(param_1 + 0x28);
      bVar1 = bVar1 ^ 1;
    }
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}

