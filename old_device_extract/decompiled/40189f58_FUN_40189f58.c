// Function : FUN_40189f58
// Address  : 0x40189f58
// Size     : 204 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40189f58(int param_1,int param_2,short param_3)

{
  uint uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_40147fe4(1,0x800,1,"ull rap",&DAT_3f423a5e,0x3f7);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = *(ushort *)(param_2 + 0xc);
  for (uVar1 = 0; (int)uVar1 < (int)(uint)*(ushort *)(param_2 + 0xe); uVar1 = uVar1 + 1) {
    piVar3 = (int *)(uVar1 * 4 + *(int *)(param_2 + 0x18));
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      if (0x7fe < (param_3 + 0x1000 + (uVar2 ^ 0xffff) & 0xfff)) goto LAB_40189fd2;
      _DAT_3ffc7952 = _DAT_3ffc7952 + 1;
      memw();
    }
    else {
      *piVar3 = 0;
      *(uint *)(param_2 + 4) = *(int *)(param_2 + 4) - (uint)*(ushort *)(iVar4 + 0x16);
      *(short *)(param_2 + 8) = *(short *)(param_2 + 8) + -1;
      memw();
      memw();
      FUN_40189de4(param_1);
    }
    uVar2 = uVar2 + 1 & 0xfff;
  }
  memw();
LAB_40189fd2:
  FUN_401868c0(param_2,uVar1 & 0xff);
  if ((param_3 + (uVar2 ^ 0xffff) & 0xfff) < 0x7ff) {
    *(short *)(param_2 + 0xc) = param_3;
    memw();
    memw();
    return;
  }
  *(ushort *)(param_2 + 0xc) = uVar2;
  memw();
  memw();
  return;
}

