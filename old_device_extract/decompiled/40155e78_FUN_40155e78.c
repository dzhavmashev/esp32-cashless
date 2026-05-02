// Function : FUN_40155e78
// Address  : 0x40155e78
// Size     : 755 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_40155e78(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  ushort uVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint auStack_60 [8];
  byte bStack_40;
  uint uStack_30;
  
  iVar6 = _DAT_3ffbfc54;
  if (DAT_3ffc8808 == '\x02') {
    return 1;
  }
  iVar7 = *(int *)(param_2 + 0x24);
  iVar3 = FUN_40186a1c(iVar7);
  if (iVar3 == 0) {
    if (*(uint *)(iVar6 + 4) != (uint)*(byte *)(iVar7 + 1)) {
      return 0;
    }
    iVar3 = (*(code *)&SUB_4008b33c)(iVar6 + 8,iVar7 + 2);
    if (iVar3 != 0) {
      return 0;
    }
  }
  if ((*(char *)(iVar6 + 0x92) != '\0') &&
     (iVar3 = (*(code *)&SUB_4008b33c)(iVar6 + 0x93,param_1 + 0x10,6), iVar3 != 0)) {
    return 0;
  }
  uVar2 = *(ushort *)(param_2 + 6);
  if ((uVar2 & 2) != 0) {
    return 0;
  }
  if (*(char *)(_DAT_3ffc8800 + 0x154) == '\x05') {
    return 1;
  }
  uVar9 = 1;
  if (1 < *(int *)(_DAT_3ffc8800 + 0x98) - 2U) {
    uVar9 = uVar2 & 2;
  }
  if (*(int *)(_DAT_3ffc8800 + 0x98) == 5 || uVar9 != 0) {
    return 0;
  }
  if ((*(int *)(param_2 + 0x3c) == 0) && (*(int *)(param_2 + 0x34) == 0)) {
    if (*(int *)(param_2 + 0x38) != 0) {
      FUN_40155e30();
      FUN_4014d67c(param_2);
      *(uint *)(_DAT_3ffc8800 + 0xa4) = *(uint *)(_DAT_3ffc8800 + 0xa4) | 0x10;
      memw();
      goto LAB_401560de;
    }
    if ((uVar2 & 0x10) == 0) {
      FUN_40155e30();
      *(uint *)(_DAT_3ffc8800 + 0xa4) = *(uint *)(_DAT_3ffc8800 + 0xa4) & 0xffffffef;
      *(undefined1 *)(param_2 + 0x7c) = 0;
      memw();
      goto LAB_401560de;
    }
    auStack_60[0] = (*(code *)&SUB_4008c01c)(iVar6 + 0x2f);
    if ((_DAT_3ffc89a4 == 0) || (*(code **)(_DAT_3ffc89a4 + 0x38) == (code *)0x0)) {
      pcVar11 = "isabled";
      uVar10 = 8;
LAB_40156117:
      FUN_40147fe4(1,uVar10,1,pcVar11);
      return 0;
    }
    memw();
    iVar6 = (**(code **)(_DAT_3ffc89a4 + 0x38))(iVar6 + 0x2f,auStack_60);
    if ((iVar6 == 0) || ((auStack_60[0] & 0xfffffff7) != 5)) {
      FUN_40147fe4(1,8,2,0x3f436b71,_DAT_3ffbfc54 + 0x2f);
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar6);
      return 0;
    }
    FUN_40155e30();
    if (auStack_60[0] == 5) {
      DAT_3ffc89ee = 7;
LAB_40156073:
      memw();
    }
    else if (auStack_60[0] == 0xd) {
      DAT_3ffc89ee = 8;
      goto LAB_40156073;
    }
    uStack_30 = 0x10;
    memw();
    (*(code *)&SUB_4008b530)(0x3ffc89dc,0,0x10);
    (*(code *)&SUB_4008b3d0)(0x3ffc89dc,iVar6,auStack_60[0]);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar6);
    *(uint *)(_DAT_3ffc8800 + 0xa4) = *(uint *)(_DAT_3ffc8800 + 0xa4) | uStack_30;
    uVar4 = 1;
  }
  else {
    cVar1 = *(char *)(iVar6 + 0x361);
    FUN_40155e30();
    iVar6 = _DAT_3ffc8800;
    *(undefined1 *)(param_2 + 0x7c) = 0;
    memw();
    uVar5 = *(uint *)(iVar6 + 0xa4) & 0xffffffef;
    iVar3 = *(int *)(param_2 + 0x3c);
    *(uint *)(iVar6 + 0xa4) = uVar5;
    if (iVar3 == 0) {
LAB_40155f35:
      iVar6 = 0;
      memw();
    }
    else {
      *(uint *)(iVar6 + 0xa4) = uVar5 | 0x10;
      memw();
      iVar6 = FUN_4014d0c0(param_2);
      if (iVar6 == 0) goto LAB_40155f35;
      memw();
      FUN_40147fe4(1,8,4,0x3f4339e4,DAT_3ffc89f0,DAT_3ffc89ee,DAT_3ffc89ed);
    }
    if ((((*(int *)(param_2 + 0x34) == 0) || (cVar1 != '\0')) ||
        (*(char *)(_DAT_3ffbfc54 + 0x364) != '\0')) || (_DAT_3ffc89a8 != 0)) {
      if (iVar6 == 0) {
        return 0;
      }
      goto LAB_401560de;
    }
    if (iVar6 == 0) {
      FUN_40155e30();
      *(uint *)(_DAT_3ffc8800 + 0xa4) = *(uint *)(_DAT_3ffc8800 + 0xa4) | 0x10;
      memw();
      FUN_4014ce0c(param_2);
      uVar4 = 2;
    }
    else {
      iVar6 = FUN_4014ce0c(param_2);
      if (iVar6 == 0) goto LAB_401560de;
      FUN_40155e30();
      FUN_4014d0c0(param_2);
      uVar4 = 4;
    }
  }
  *(undefined1 *)(param_2 + 0x7c) = uVar4;
  memw();
  memw();
LAB_401560de:
  iVar6 = *(int *)(param_2 + 0x2c);
  if (iVar6 != 0) {
    pbVar8 = (byte *)(iVar6 + 2);
    memw();
    for (; (int)pbVar8 - iVar6 <= (int)(*(byte *)(iVar6 + 1) + 1); pbVar8 = pbVar8 + 1) {
      if ((((*pbVar8 & 0x7f) == 0x7b) && (*(char *)(_DAT_3ffbfc54 + 0x499) == '\0')) &&
         (*(char *)(param_2 + 0x7c) == '\x06')) {
        pcVar11 = "_wpa_ie";
        uVar10 = 4;
        goto LAB_40156117;
      }
    }
  }
  iVar6 = *(int *)(param_2 + 0x80);
  if (iVar6 != 0) {
    if ((_DAT_3ffc89a4 == 0) || (*(code **)(_DAT_3ffc89a4 + 0x3c) == (code *)0x0)) {
      FUN_40147fe4(1,8,1,"_wpa_ie");
    }
    else {
      iVar6 = (**(code **)(_DAT_3ffc89a4 + 0x3c))(iVar6,*(byte *)(iVar6 + 1) + 2,auStack_60);
      if (iVar6 != 0) {
        return 0;
      }
      if ((*(char *)(_DAT_3ffbfc54 + 0x499) != '\0') && ((bStack_40 & 0x20) != 0)) {
        DAT_3ffc8a69 = 1;
        memw();
        memw();
      }
    }
  }
  return 1;
}

