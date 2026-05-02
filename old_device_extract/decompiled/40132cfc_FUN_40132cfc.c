// Function : FUN_40132cfc
// Address  : 0x40132cfc
// Size     : 61 bytes


undefined4 FUN_40132cfc(int *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  uVar1 = 0xffff9f00;
  if ((iVar2 != 0) && (uVar1 = 0xffff9f80, param_3 < 0x11)) {
    uVar3 = param_3;
    if ((*(uint *)(iVar2 + 0x14) & 1) == 0) {
      uVar3 = *(uint *)(iVar2 + 0x10);
      uVar1 = 0xffff9f00;
      if (param_3 < uVar3) goto LAB_40132d34;
    }
    uVar1 = 0;
    if (uVar3 != 0) {
      (*(code *)&SUB_4008b3d0)(param_1 + 10,param_2,uVar3);
      uVar1 = 0;
      param_1[0xe] = uVar3;
    }
  }
LAB_40132d34:
  memw();
  return uVar1;
}

