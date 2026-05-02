// Function : FUN_400f85a4
// Address  : 0x400f85a4
// Size     : 214 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f85a4(int param_1,uint param_2,int *param_3,undefined1 *param_4,uint param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint in_t0;
  byte abStack_35 [17];
  uint uStack_24;
  
  iVar4 = param_3[0x37];
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar3 = (iVar4 + 0x10U & 0xfffffff0) - iVar4;
  if ((param_1 != 0) || ((param_5 ^ 1) != 0)) {
    memw();
    iVar4 = FUN_400f8574(iVar4 + *param_3,abStack_35 + 1,iVar3,1);
    if (iVar4 != 0) goto LAB_400f8631;
  }
  uVar5 = (uint)abStack_35[iVar3];
  uVar2 = (param_2 >> 0x18 ^ param_2 >> 0x10 ^ param_2 ^ param_2 >> 8) & 0xff;
  if ((uVar5 != uVar2) && ((param_5 ^ 1) != 0)) goto LAB_400f8649;
  if (param_1 != 0) {
    memw();
    FUN_400f8b50(param_1,abStack_35 + 1,iVar3);
  }
  iVar4 = 0;
  param_3[0x37] = param_3[0x37] + iVar3;
  memw();
LAB_400f8631:
  while( true ) {
    uVar5 = in_t0;
    uVar2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
    param_4 = &DAT_3ffc5708;
    in_t0 = uVar5;
LAB_400f8649:
    iVar4 = 0x2002;
    if (param_4 == (undefined1 *)0x0) {
      memw();
      uVar1 = (*(code *)&SUB_40094b80)();
      memw();
      iVar4 = 0x2002;
      FUN_4012113c(1,"_common","p_image",uVar1,"_common",uVar2,uVar5);
    }
  }
  return iVar4;
}

