// Function : FUN_40122bdc
// Address  : 0x40122bdc
// Size     : 31 bytes


int FUN_40122bdc(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  return ((uVar1 >> 0xd & 1) + 1) * 0x830 + 0x3ffbe550;
}

