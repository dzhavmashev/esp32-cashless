// Function : FUN_40121b0c
// Address  : 0x40121b0c
// Size     : 19 bytes


undefined4 FUN_40121b0c(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  uVar1 = (*(code *)&SUB_400916e4)(uVar2 >> 0xd & 1);
  return uVar1;
}

