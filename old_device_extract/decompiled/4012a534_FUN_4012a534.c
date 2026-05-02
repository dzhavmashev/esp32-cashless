// Function : FUN_4012a534
// Address  : 0x4012a534
// Size     : 478 bytes


undefined4 FUN_4012a534(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = param_1[0x34];
  cVar1 = *(char *)param_1[0x33];
  if ((uVar5 & 0xfffffffd) != 0x14) {
    return 0xffff9400;
  }
  if (((uVar5 != 0x16) || (cVar1 != '\0')) && (param_1[0x11] == 0)) {
    return 0xffff9400;
  }
  if (((*(char *)(*param_1 + 5) == '\x01') && (param_1[0x11] != 0)) &&
     (*(char *)(param_1[0x11] + 7) == '\x01')) {
    return 0xffff9400;
  }
  if (0x4000 < (uint)param_1[0x35]) {
    return 0xffff9400;
  }
  if (uVar5 == 0x16) {
    iVar3 = param_1[0x35] - 4;
    ((char *)param_1[0x33])[1] = (char)((uint)iVar3 >> 0x10);
    memw();
    *(char *)(param_1[0x33] + 2) = (char)((uint)iVar3 >> 8);
    memw();
    *(char *)(param_1[0x33] + 3) = (char)iVar3;
    memw();
    if (*(char *)(*param_1 + 5) == '\x01') {
      if (0x4000U - param_1[0x35] < 8) {
        return 0xffff8f00;
      }
      memw();
      (*(code *)&SUB_4008b4c8)(param_1[0x33] + 0xc,param_1[0x33] + 4);
      param_1[0x35] = param_1[0x35] + 8;
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1[0x33] + 4) = 0;
        memw();
        *(undefined1 *)(param_1[0x33] + 5) = 0;
        memw();
        memw();
      }
      else {
        *(char *)(param_1[0x33] + 4) = (char)((uint)*(undefined4 *)(param_1[0x11] + 0x238) >> 8);
        memw();
        *(char *)(param_1[0x33] + 5) = (char)*(undefined4 *)(param_1[0x11] + 0x238);
        memw();
        *(int *)(param_1[0x11] + 0x238) = *(int *)(param_1[0x11] + 0x238) + 1;
      }
      memw();
      (*(code *)&SUB_4008b530)(param_1[0x33] + 6,0,3);
      iVar3 = param_1[0x33];
      *(undefined1 *)(iVar3 + 9) = *(undefined1 *)(iVar3 + 1);
      memw();
      *(undefined1 *)(iVar3 + 10) = *(undefined1 *)(iVar3 + 2);
      *(undefined1 *)(iVar3 + 0xb) = *(undefined1 *)(iVar3 + 3);
      memw();
      if (cVar1 == '\0') goto LAB_4012a670;
    }
    else if (cVar1 == '\0') goto LAB_4012a708;
    memw();
    (**(code **)(param_1[0x11] + 0x18))(param_1,param_1[0x33],param_1[0x35]);
  }
LAB_4012a670:
  if ((*(char *)(*param_1 + 5) == '\x01') && ((param_1[0x34] != 0x16 || (cVar1 != '\0')))) {
    piVar2 = (int *)FUN_4013ae30(1,0x10);
    if (piVar2 == (int *)0x0) {
      return 0xffff8100;
    }
    iVar3 = FUN_4013ae30(1,param_1[0x35]);
    *piVar2 = iVar3;
    if (iVar3 == 0) {
      memw();
      FUN_4013ae44(piVar2);
      return 0xffff8100;
    }
    (*(code *)&SUB_4008b3d0)(iVar3,param_1[0x33],param_1[0x35]);
    piVar2[1] = param_1[0x35];
    *(char *)(piVar2 + 2) = (char)param_1[0x34];
    memw();
    piVar2[3] = 0;
    iVar3 = *(int *)(param_1[0x11] + 0x24c);
    if (iVar3 == 0) {
      *(int **)(param_1[0x11] + 0x24c) = piVar2;
      memw();
      return 0;
    }
    do {
      iVar6 = iVar3;
      iVar3 = *(int *)(iVar6 + 0xc);
    } while (iVar3 != 0);
    *(int **)(iVar6 + 0xc) = piVar2;
    memw();
    return 0;
  }
LAB_4012a708:
  uVar4 = FUN_40129e24(param_1,1);
  return uVar4;
}

