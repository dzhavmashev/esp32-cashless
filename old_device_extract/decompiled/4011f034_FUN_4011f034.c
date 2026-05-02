// Function : FUN_4011f034
// Address  : 0x4011f034
// Size     : 29 bytes


int FUN_4011f034(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_4011f018();
  iVar2 = 0x400000;
  if (uVar1 < 0x400000) {
    iVar2 = FUN_4011f018();
  }
  iVar3 = FUN_40185604();
  return iVar2 - iVar3;
}

