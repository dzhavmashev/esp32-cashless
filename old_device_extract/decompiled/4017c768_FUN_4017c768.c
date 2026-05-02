// Function : FUN_4017c768
// Address  : 0x4017c768
// Size     : 72 bytes


undefined8 FUN_4017c768(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (param_2 & 0x7ff00000) + 0xfcc00000;
  if (iVar2 < 1) {
    uVar3 = -iVar2 >> 0x14;
    if (0x13 < (int)uVar3) {
      iVar2 = 0;
      uVar1 = 1;
      if ((int)(uVar3 - 0x14) < 0x1f) {
        uVar1 = 0x80000000 >> (uVar3 - 0x14 & 0x1f);
      }
      goto LAB_4017c7ae;
    }
    iVar2 = 0x80000 >> (uVar3 & 0x1f);
  }
  uVar1 = 0;
LAB_4017c7ae:
  return CONCAT44(iVar2,uVar1);
}

