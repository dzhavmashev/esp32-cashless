// Function : FUN_4014dfdc
// Address  : 0x4014dfdc
// Size     : 451 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014dfdc(char param_1,uint param_2,char param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  uint local_30;
  char local_2c [44];
  
  memw();
  memw();
  local_30 = param_2;
  local_2c[0] = param_3;
  iVar3 = FUN_40150e2c();
  iVar2 = _DAT_3ffc8804;
  iVar4 = _DAT_3ffc8800;
  if (*(char *)(_DAT_3ffbfc54 + 1) == local_2c[0]) {
    if (param_1 == '\0') {
      if (*(byte *)(_DAT_3ffbfc54 + 0x9c) != local_30) goto LAB_4014e03b;
      iVar4 = FUN_40151060(10,&local_30);
      if (iVar4 != 0) {
        uVar5 = 10;
        *(char *)(iVar3 + 0x9c) = (char)local_30;
        memw();
        if (DAT_3ffc8a05 == '\0') {
          param_1 = '\x01';
        }
        memw();
        cVar6 = param_1;
LAB_4014e14e:
        memw();
        iVar4 = FUN_40150e8c(uVar5,local_30,cVar6);
        goto joined_r0x4014e154;
      }
    }
    else if (param_1 == '\x01') {
      if (*(byte *)(_DAT_3ffbfc54 + 0x3fa) != local_30) goto LAB_4014e0a5;
      iVar4 = FUN_40151060(0x1f,&local_30);
      if (iVar4 != 0) {
        uVar5 = 0x1f;
        *(char *)(iVar3 + 0x3fa) = (char)local_30;
        memw();
        cVar6 = '\0';
        if (DAT_3ffc8a05 == '\0') {
          cVar6 = param_1;
        }
        goto LAB_4014e14e;
      }
    }
LAB_4014e15a:
    iVar4 = FUN_40151060(0x25,local_2c);
    if (iVar4 != 0) {
      *(char *)(iVar3 + 1) = local_2c[0];
      memw();
      memw();
      FUN_40150e8c(0x25,local_2c[0],DAT_3ffc8a05 == '\0');
    }
  }
  else {
    *(char *)(iVar3 + 1) = local_2c[0];
    memw();
    memw();
    FUN_40150e8c(0x25,local_2c[0],DAT_3ffc8a05 == '\0');
    if (param_1 == '\0') {
LAB_4014e03b:
      *(char *)(iVar3 + 0x9c) = (char)local_30;
      memw();
      if (iVar4 != 0) {
        *(char *)(iVar4 + 0x168) = (char)local_30;
        memw();
        memw();
        FUN_4015469c(iVar4);
      }
      if (local_30 == 3) {
        if (iVar4 != 0) {
          FUN_4014a9bc(iVar4);
        }
      }
      else {
        if (iVar4 != 0) {
          FUN_4014aea0(iVar4);
        }
        FUN_4014de24(0,1);
      }
      uVar5 = 10;
      uVar1 = *(undefined1 *)(iVar3 + 0x9c);
    }
    else {
      if (param_1 != '\x01') goto LAB_4014e15a;
LAB_4014e0a5:
      *(char *)(iVar3 + 0x3fa) = (char)local_30;
      memw();
      if (iVar2 != 0) {
        *(char *)(iVar2 + 0x168) = (char)local_30;
        memw();
        memw();
        FUN_4015469c(iVar2);
      }
      if (local_30 == 3) {
        if (iVar2 != 0) {
          FUN_4014a9bc(iVar2);
        }
      }
      else {
        if (iVar2 != 0) {
          FUN_4014aea0(iVar2);
        }
        FUN_4014de24(1);
      }
      uVar5 = 0x1f;
      uVar1 = *(undefined1 *)(iVar3 + 0x3fa);
    }
    iVar4 = FUN_40150e8c(uVar5,uVar1,DAT_3ffc8a05 == '\0');
joined_r0x4014e154:
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  DAT_3ffc8a04 = 1;
  memw();
  memw();
  iVar4 = FUN_40150e38();
  return iVar4;
}

