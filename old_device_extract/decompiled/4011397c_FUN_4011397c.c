// Function : FUN_4011397c
// Address  : 0x4011397c
// Size     : 484 bytes


char FUN_4011397c(int param_1,int param_2,uint *param_3,undefined2 param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  if ((param_2 == 0 || (param_3 == (uint *)0x0 || (param_5 == 0 || param_6 == 0))) || (param_1 == 0)
     ) {
    return -0x10;
  }
  if ((*(char *)(param_1 + 0x14) != '.') &&
     ((*(char *)(param_6 + 0x14) != *(char *)(param_1 + 0x14) ||
      ((char)param_3[5] != *(char *)(param_6 + 0x14))))) {
    return -6;
  }
  if ((*(short *)(param_1 + 0x3a) == 0) && (cVar2 = FUN_40113770(param_1,param_1), cVar2 != '\0')) {
    return cVar2;
  }
  if (*(ushort *)(param_2 + 8) < 0xfff8) {
    iVar4 = FUN_4010ba7c(param_2,8);
    iVar5 = param_2;
    if (iVar4 != 0) {
      iVar5 = FUN_4010bbc4(0x36,8,0x280);
      if (iVar5 == 0) goto LAB_401139dc;
      if (*(short *)(param_2 + 8) != 0) {
        FUN_4010bea0(iVar5,param_2);
      }
    }
    if (*(ushort *)(iVar5 + 10) < 8) {
      (*(code *)&SUB_40094c54)("lid pcb",0x31b,"udp_hdr","failed\n");
    }
    puVar7 = *(undefined1 **)(iVar5 + 4);
    uVar3 = FUN_40185290(*(undefined2 *)(param_1 + 0x3a));
    *puVar7 = (char)uVar3;
    puVar7[1] = (char)((ushort)uVar3 >> 8);
    memw();
    memw();
    uVar3 = FUN_40185290(param_4);
    puVar7[2] = (char)uVar3;
    puVar7[3] = (char)((ushort)uVar3 >> 8);
    puVar7[6] = 0;
    puVar7[7] = 0;
    memw();
    if ((*(byte *)(param_1 + 0x38) & 8) != 0) {
      if ((char)param_3[5] == '\x06') {
        uVar8 = *param_3 & 0xff;
        uVar6 = 0xffffff01;
      }
      else {
        uVar6 = *param_3 & 0xf0;
        uVar8 = 0xffffff20;
      }
      if (uVar6 + uVar8 == 0) {
        *(byte *)(iVar5 + 0xd) = *(byte *)(iVar5 + 0xd) | 4;
        memw();
      }
    }
    memw();
    uVar3 = FUN_40185290(*(undefined2 *)(iVar5 + 8));
    puVar7[4] = (char)uVar3;
    puVar7[5] = (char)((ushort)uVar3 >> 8);
    memw();
    if (((char)param_3[5] == '\x06') || ((*(byte *)(param_1 + 0x38) & 1) == 0)) {
      memw();
      iVar4 = FUN_4011dc38(iVar5,0x11,*(undefined2 *)(iVar5 + 8),param_6,param_3);
      if (iVar4 == 0) {
        iVar4 = 0xffff;
      }
      puVar7[6] = (char)iVar4;
      puVar7[7] = (char)((uint)iVar4 >> 8);
      memw();
    }
    if ((char)param_3[5] == '\x06') {
      uVar6 = 0xff;
      iVar4 = -0xff;
    }
    else {
      uVar6 = 0xf0;
      iVar4 = -0xe0;
    }
    if ((*param_3 & uVar6) + iVar4 == 0) {
      uVar1 = *(undefined1 *)(param_1 + 0x45);
    }
    else {
      uVar1 = *(undefined1 *)(param_1 + 0x33);
    }
    if ((char)param_3[5] == '\x06') {
      memw();
      cVar2 = FUN_40117c04();
    }
    else {
      cVar2 = FUN_40116d2c(iVar5,param_6,param_3,uVar1,*(undefined1 *)(param_1 + 0x32),0x11,param_5)
      ;
    }
    if (iVar5 != param_2) {
      memw();
      FUN_4010bb10(iVar5);
    }
  }
  else {
LAB_401139dc:
    cVar2 = -1;
    memw();
  }
  return cVar2;
}

