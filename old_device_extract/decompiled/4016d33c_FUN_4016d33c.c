// Function : FUN_4016d33c
// Address  : 0x4016d33c
// Size     : 85 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4016d33c(undefined1 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  (**(code **)(_DAT_3ffc7e64 + 0x44))(1,0x80,param_1,0,0);
  iVar3 = 0;
  iVar2 = 4;
  do {
    iVar2 = iVar2 + -1;
    sVar1 = (**(code **)(_DAT_3ffc7e64 + 0x178))(_DAT_3ffca42c);
    iVar3 = (int)(short)(sVar1 + (short)iVar3);
  } while (iVar2 != 0);
  (**(code **)(_DAT_3ffc7e64 + 0x4c))(1);
  iVar2 = iVar3 + 4;
  if (iVar3 + 4 < 0) {
    iVar2 = iVar3 + 0xb;
  }
  return (int)(short)(iVar2 >> 3);
}

