// Function : caseD_0
// Address  : 0x40164880
// Size     : 27 bytes


int switchD_40164a01::caseD_0(int param_1,uint param_2)

{
  int unaff_a8;
  uint uVar1;
  uint unaff_a9;
  
  if (unaff_a9 < param_2) {
    return param_1;
  }
  uVar1 = (unaff_a8 >> 1) * 3 & 0xff;
  return (uVar1 < 0x20) * uVar1 + (uint)(uVar1 >= 0x20) * 0x20;
}

