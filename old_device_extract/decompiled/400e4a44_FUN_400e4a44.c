// Function : FUN_400e4a44
// Address  : 0x400e4a44
// Size     : 30 bytes


bool FUN_400e4a44(undefined4 param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_400f80b4(0);
  bVar1 = false;
  if (iVar2 != 0) {
    bVar1 = param_2 <= *(uint *)(iVar2 + 0x10);
  }
  return bVar1;
}

