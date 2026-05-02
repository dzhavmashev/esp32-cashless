// Function : FUN_40124e4c
// Address  : 0x40124e4c
// Size     : 359 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40124e4c(int *param_1)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int in_a7;
  undefined4 uVar6;
  byte *in_a13;
  undefined4 uStack_5c;
  uint uStack_58;
  byte *pbStack_54;
  byte abStack_4e [42];
  int *piStack_24;
  
  memw();
  piVar1 = param_1 + 0x40;
  memw();
  piStack_24 = _DAT_3ffc5708;
  iVar5 = 0;
  uVar4 = param_1[1];
  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
  memw();
  param_1[4] = 10;
  iVar2 = param_1[0xb];
  param_1[0xd] = 0;
  param_1[0xb] = iVar2 + 1;
  if (4 < iVar2 + 1) goto LAB_40124f81;
  iVar2 = *param_1;
  abStack_4e[2] = 0;
  abStack_4e[3] = 0;
  abStack_4e[4] = 0;
  abStack_4e[5] = 0;
  abStack_4e[6] = 0;
  abStack_4e[7] = 0;
  abStack_4e[8] = 0;
  abStack_4e[9] = 0;
  in_a13 = *(byte **)(iVar2 + 0x54);
  in_a7 = *(int *)(iVar2 + 0x58);
  if (param_1[0x6d] == 1) {
    if ((((*(uint *)(iVar2 + 4) & 2) != 0) && ((int)(in_a13[1] + 2) < in_a7)) && (*in_a13 == 0x30))
    {
      in_a13 = in_a13 + in_a13[1] + 2;
      in_a7 = in_a13[1] + 2;
    }
  }
  else if (param_1[0x6d] == 2) {
    iVar5 = *(int *)(uVar4 + 0x14);
    if (*(int *)(iVar2 + 0x48) != 0) goto LAB_40124f98;
    pbVar3 = (byte *)(uVar4 + *(int *)(uVar4 + 0x18) * 0x20 + 0x48);
    goto LAB_40124ee1;
  }
  uVar4 = 0;
  pbVar3 = (byte *)0x0;
  uStack_58 = *(byte *)(param_1 + 0x67) >> 5 & 1;
  iVar5 = 0;
  uStack_5c = 0;
  pbStack_54 = (byte *)0x0;
  memw();
  do {
    iVar2 = 0x1e;
    if ((*(byte *)(piVar1 + 0x27) & 0x10) == 0) {
      iVar2 = 0;
    }
    iVar2 = iVar2 + in_a7;
    if (pbVar3 != (byte *)0x0) {
      iVar2 = iVar2 + iVar5 + 8;
    }
    memw();
    piVar1 = (int *)(*(code *)&SUB_40094d60)(iVar2);
    if (piVar1 != (int *)0x0) {
      (*(code *)&SUB_4008b3d0)(piVar1,in_a13,in_a7);
      iVar2 = (int)piVar1 + in_a7;
      if (pbVar3 != (byte *)0x0) {
        abStack_4e[0] = (byte)uStack_5c & 3;
        abStack_4e[1] = 0;
        memw();
        memw();
        iVar2 = FUN_40125ca4(iVar2,0xfac01,abStack_4e,2,pbVar3,iVar5);
      }
      iVar2 = FUN_40124380(param_1,iVar2);
      uVar6 = 0x3c8;
      if (uStack_58 == 0) {
        uVar6 = 0x1c8;
      }
      memw();
      FUN_40124bb4(*param_1,param_1,uVar6,pbStack_54,param_1 + 0x13,piVar1,iVar2 - (int)piVar1,
                   uStack_5c,uVar4);
      (*(code *)&SUB_40094d80)(piVar1);
      uVar4 = uStack_58;
      in_a13 = pbStack_54;
    }
LAB_40124f81:
    do {
      param_1 = _DAT_3ffc5708;
      memw();
      memw();
      if (piStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_40124f98:
      memw();
      iVar2 = FUN_40102858(abStack_4e + 10,iVar5);
    } while (iVar2 < 0);
    pbVar3 = abStack_4e + 10;
LAB_40124ee1:
    uStack_5c = *(undefined4 *)(uVar4 + 0x18);
    pbStack_54 = abStack_4e + 2;
    uVar4 = 1;
    uStack_58 = 1;
  } while( true );
}

