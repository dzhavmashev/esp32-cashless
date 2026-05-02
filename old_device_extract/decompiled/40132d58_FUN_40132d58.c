// Function : FUN_40132d58
// Address  : 0x40132d58
// Size     : 455 bytes


int FUN_40132d58(int *param_1,int param_2,int *param_3,int param_4,uint *param_5)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  iVar3 = *param_1;
  if (iVar3 == 0) {
    return -0x6100;
  }
  *param_5 = 0;
  piVar2 = *(int **)(iVar3 + 0x18);
  if (piVar2 == (int *)0x0) {
    return -0x6380;
  }
  iVar4 = *(int *)(iVar3 + 4);
  if (iVar4 == 1) {
    if (param_3 == piVar2) {
      *param_5 = (uint)param_3;
      memw();
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x1c) + 4))(param_1[0xf],param_1[2],param_2,param_4);
      return iVar3;
    }
    return -0x6280;
  }
  if (iVar4 == 6) {
    iVar3 = param_1[0xf];
    *param_5 = (uint)param_3;
    memw();
    iVar3 = FUN_4014138c(iVar3,param_3,param_2,param_4);
    return iVar3;
  }
  if (param_2 == param_4) {
    if (param_1[9] != 0) {
      return -0x6100;
    }
    if ((uint)param_3 % (uint)piVar2 != 0) {
      return -0x6100;
    }
  }
  if (iVar4 == 2) {
    iVar3 = param_1[9];
    if (param_1[2] == 0) {
      piVar5 = (int *)((int)piVar2 - iVar3);
      if (param_1[3] == 0) {
LAB_40132dfe:
        if (piVar5 <= param_3) goto LAB_40132e01;
      }
      else if (piVar5 < param_3) goto LAB_40132e01;
      (*(code *)&SUB_4008b3d0)((int)param_1 + iVar3 + 0x14,param_2,param_3);
      param_1[9] = param_1[9] + (int)param_3;
    }
    else {
      if (param_1[2] == 1) {
        piVar5 = (int *)((int)piVar2 - iVar3);
        goto LAB_40132dfe;
      }
LAB_40132e01:
      if (iVar3 != 0) {
        memw();
        (*(code *)&SUB_4008b3d0)((int)param_1 + iVar3 + 0x14,param_2,(int)piVar2 - iVar3);
        iVar4 = (**(code **)(*(int *)(*param_1 + 0x1c) + 8))
                          (param_1[0xf],param_1[2],piVar2,param_1 + 10,param_1 + 5,param_4);
        if (iVar4 != 0) {
          return iVar4;
        }
        param_4 = param_4 + (int)piVar2;
        param_3 = (int *)((int)param_3 + (iVar3 - (int)piVar2));
        *param_5 = *param_5 + (int)piVar2;
        param_2 = param_2 + ((int)piVar2 - iVar3);
        param_1[9] = 0;
      }
      if (param_3 != (int *)0x0) {
        piVar5 = (int *)((uint)param_3 % (uint)piVar2);
        if (((piVar5 == (int *)0x0) && (param_1[2] == 0)) && (param_1[3] != 0)) {
          piVar5 = piVar2;
        }
        iVar3 = (int)param_3 - (int)piVar5;
        memw();
        (*(code *)&SUB_4008b3d0)(param_1 + 5,param_2 + iVar3,piVar5);
        param_1[9] = param_1[9] + (int)piVar5;
        if (iVar3 != 0) {
          memw();
          iVar4 = (**(code **)(*(int *)(*param_1 + 0x1c) + 8))
                            (param_1[0xf],param_1[2],iVar3,param_1 + 10,param_2,param_4);
          if (iVar4 != 0) {
            return iVar4;
          }
          param_3 = (int *)(*param_5 + iVar3);
          goto LAB_40132e9f;
        }
      }
    }
    memw();
  }
  else {
    if (iVar4 == 3) {
      piVar7 = param_1 + 10;
      piVar6 = param_1 + 9;
      pcVar1 = *(code **)(*(int *)(iVar3 + 0x1c) + 0xc);
      piVar2 = (int *)param_1[2];
      piVar5 = param_3;
LAB_40132ebd:
      memw();
      iVar3 = (*pcVar1)(param_1[0xf],piVar2,piVar5,piVar6,piVar7,param_2,param_4);
    }
    else {
      if (iVar4 == 4) {
        pcVar1 = *(code **)(*(int *)(iVar3 + 0x1c) + 0x10);
        piVar2 = param_3;
        piVar5 = param_1 + 9;
      }
      else {
        if (iVar4 == 5) {
          piVar7 = param_1 + 5;
          piVar6 = param_1 + 10;
          piVar5 = param_1 + 9;
          pcVar1 = *(code **)(*(int *)(iVar3 + 0x1c) + 0x14);
          memw();
          piVar2 = param_3;
          goto LAB_40132ebd;
        }
        if (iVar4 != 9) {
          return -0x6080;
        }
        if (param_1[9] != 0) {
          return -0x6080;
        }
        pcVar1 = *(code **)(*(int *)(iVar3 + 0x1c) + 0x18);
        piVar2 = (int *)param_1[2];
        piVar5 = param_3;
      }
      iVar3 = (*pcVar1)(param_1[0xf],piVar2,piVar5,param_1 + 10,param_2,param_4);
    }
    if (iVar3 != 0) {
      return iVar3;
    }
LAB_40132e9f:
    *param_5 = (uint)param_3;
    memw();
  }
  return 0;
}

