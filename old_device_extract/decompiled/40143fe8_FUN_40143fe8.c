// Function : FUN_40143fe8
// Address  : 0x40143fe8
// Size     : 284 bytes


/* WARNING: Type propagation algorithm not settling */

int FUN_40143fe8(uint *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iStack_4c;
  uint auStack_48 [3];
  uint uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_24;
  
  if ((*param_1 & 0xdf) != 0x80) {
    if ((*param_1 & 0xdf) == 0x82) {
      (*(code *)&SUB_4008b530)(param_2 + 1,0,0x24);
      *param_2 = 2;
      memw();
      (*(code *)&SUB_4008b3d0)(param_2 + 1,param_1,0xc);
      iVar3 = 0;
      goto LAB_401440d8;
    }
LAB_40144000:
    iVar3 = -0x2080;
    goto LAB_401440d8;
  }
  auStack_48[0] = param_1[2];
  iVar4 = auStack_48[0] + param_1[1];
  memw();
  iVar3 = FUN_40141738(auStack_48,iVar4,&iStack_4c,6);
  uVar2 = auStack_48[0];
  iVar1 = iStack_4c;
  if (iVar3 != 0) goto LAB_40144020;
  if ((iStack_4c != 8) ||
     (iVar3 = (*(code *)&SUB_4008b33c)(&DAT_3f4231d2,auStack_48[0],8), iVar3 != 0))
  goto LAB_40144000;
  uStack_3c = uVar2;
  auStack_48[0] = uVar2 + 8;
  auStack_48[1] = 6;
  auStack_48[2] = iVar1;
  memw();
  iVar3 = FUN_40141738(auStack_48,iVar4,&iStack_4c,0xa0);
  if (iVar3 != 0) goto LAB_40144020;
  if (iVar4 != auStack_48[0] + iStack_4c) {
LAB_401440d5:
    iVar3 = -0x2566;
    goto LAB_401440d8;
  }
  iVar3 = FUN_40141738(auStack_48,iVar4,&iStack_4c,0x30);
  if (iVar3 != 0) goto LAB_40144020;
  if (iVar4 != auStack_48[0] + iStack_4c) goto LAB_401440d5;
  iVar3 = FUN_40141738(auStack_48,iVar4,&iStack_4c,6);
  if (iVar3 == 0) {
    uStack_38 = 6;
    uStack_30 = auStack_48[0];
    auStack_48[0] = auStack_48[0] + iStack_4c;
    iStack_34 = iStack_4c;
    memw();
    iVar3 = FUN_40141738(auStack_48,iVar4,&iStack_4c);
    if (iVar3 != 0) goto LAB_40144020;
    uStack_2c = 4;
    uStack_24 = auStack_48[0];
    if (iVar4 != auStack_48[0] + iStack_4c) goto LAB_401440d5;
  }
  else {
LAB_40144020:
    iVar3 = iVar3 + -0x2500;
    if (iVar3 != 0) goto LAB_401440d8;
  }
  *param_2 = 0;
  memw();
  (*(code *)&SUB_4008b3d0)(param_2 + 1,auStack_48 + 1,0x24);
  iVar3 = 0;
LAB_401440d8:
  memw();
  return iVar3;
}

