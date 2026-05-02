// Function : FUN_40129e24
// Address  : 0x40129e24
// Size     : 415 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40129e24(int *param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  undefined1 auStack_40 [8];
  byte bStack_38;
  undefined1 auStack_37 [3];
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar6 = param_1[0x35];
  memw();
  FUN_401858e4(param_1[4],param_1[5],*(undefined1 *)(*param_1 + 5),param_1[0x30] + 1);
  (*(code *)&SUB_4008b3d0)(param_1[0x2f],param_1 + 0x37,8);
  *(char *)param_1[0x31] = (char)((uint)iVar6 >> 8);
  memw();
  *(char *)(param_1[0x31] + 1) = (char)iVar6;
  memw();
  if (param_1[0x13] != 0) {
    iStack_34 = param_1[0x32];
    iStack_30 = 0x414d - (iStack_34 - param_1[0x2e]);
    iStack_28 = param_1[0x35];
    iStack_2c = param_1[0x33] - iStack_34;
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_40,param_1[0x2f],8);
    FUN_401858e4(param_1[4],param_1[5],*(undefined1 *)(*param_1 + 5),auStack_37);
    bStack_38 = (byte)param_1[0x34];
    memw();
    memw();
    piVar3 = (int *)FUN_40129260(param_1,param_1[0x13],auStack_40,*(undefined4 *)(*param_1 + 0x4c),
                                 *(undefined4 *)(*param_1 + 0x50));
    if ((piVar3 != (int *)0x0) || (piVar3 = (int *)0xffff9400, iStack_2c != 0)) goto LAB_40129fa1;
    param_1[0x34] = (uint)bStack_38;
    param_1[0x35] = iStack_28;
    *(char *)param_1[0x31] = (char)((uint)iStack_28 >> 8);
    memw();
    *(char *)(param_1[0x31] + 1) = (char)iStack_28;
    memw();
    iVar6 = iStack_28;
  }
  piVar4 = (int *)((param_1[0x32] - param_1[0x30]) + iVar6);
  if (*(char *)(*param_1 + 5) == '\x01') {
    piVar3 = (int *)FUN_401290e4(param_1);
    if ((int)piVar3 < 0) goto LAB_40129fa1;
    if (piVar3 < piVar4) {
      piVar3 = (int *)0xffff9400;
      goto LAB_40129fa1;
    }
  }
  *(char *)param_1[0x30] = (char)param_1[0x34];
  memw();
  param_1[0x36] = param_1[0x36] + (int)piVar4;
  param_1[0x30] = param_1[0x30] + (int)piVar4;
  memw();
  FUN_40185840(param_1,param_1[0x13]);
  iVar6 = 0;
  cVar1 = *(char *)(*param_1 + 5);
  if (cVar1 == '\x01') {
    iVar6 = 2;
  }
  iVar6 = 8 - iVar6;
  pcVar5 = (char *)((int)param_1 + 0xe3);
  do {
    cVar2 = *pcVar5;
    *pcVar5 = cVar2 + '\x01';
    memw();
    if ((char)(cVar2 + '\x01') != '\0') {
      if (param_2 != 0) goto LAB_40129fb9;
      if (cVar1 != '\x01') goto LAB_40129fb9;
      memw();
      piVar3 = (int *)FUN_40129d28(param_1);
      if (-1 < (int)piVar3) {
        if (piVar3 == (int *)0x0) goto LAB_40129fbc;
        goto LAB_40129f7d;
      }
      goto LAB_40129fa1;
    }
    iVar6 = iVar6 + -1;
    pcVar5 = pcVar5 + -1;
  } while (iVar6 != 0);
  piVar3 = (int *)0xffff9480;
LAB_40129fa1:
  while( true ) {
    param_1 = piVar3;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
LAB_40129fb9:
    if (param_2 == 1) {
LAB_40129fbc:
      piVar3 = (int *)FUN_40129bc8(param_1);
    }
    else {
LAB_40129f7d:
      piVar3 = (int *)0x0;
    }
  }
  return;
}

