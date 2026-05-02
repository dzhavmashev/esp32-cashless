// Function : FUN_400f1558
// Address  : 0x400f1558
// Size     : 511 bytes


void FUN_400f1558(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  
  uVar3 = FUN_40184778(param_1);
  if ((uVar3 != 0) && (iVar4 = FUN_40184778(param_2), iVar4 != 0)) {
    iVar5 = FUN_40184778(param_3);
    cVar1 = *(char *)((int)param_1 + 0xf);
    iVar5 = iVar5 - iVar4;
    piVar11 = param_1;
    if (-1 < cVar1) {
      piVar11 = (int *)*param_1;
    }
    if (iVar5 == 0) {
      while( true ) {
        piVar12 = param_2;
        if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
          piVar12 = (int *)*param_2;
        }
        iVar4 = func_0x4008ca64(piVar11,piVar12);
        if (iVar4 == 0) break;
        piVar11 = param_3;
        if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
          piVar11 = (int *)*param_3;
        }
        uVar6 = FUN_40184778(param_3);
        func_0x4008b4d0(iVar4,piVar11,uVar6);
        iVar5 = FUN_40184778(param_3);
        piVar11 = (int *)(iVar4 + iVar5);
      }
    }
    else {
      iVar7 = (int)piVar11;
      if (iVar5 < 0) {
        while( true ) {
          piVar12 = param_2;
          if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
            piVar12 = (int *)*param_2;
          }
          iVar4 = func_0x4008ca64(iVar7,piVar12);
          if (iVar4 == 0) break;
          func_0x4008b4d0(piVar11,iVar7,iVar4 - iVar7);
          iVar7 = (int)piVar11 + (iVar4 - iVar7);
          piVar11 = param_3;
          if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
            piVar11 = (int *)*param_3;
          }
          uVar6 = FUN_40184778(param_3);
          func_0x4008b4d0(iVar7,piVar11,uVar6);
          iVar8 = FUN_40184778(param_3);
          piVar11 = (int *)(iVar7 + iVar8);
          iVar7 = FUN_40184778(param_2);
          uVar3 = uVar3 + iVar5;
          iVar7 = iVar4 + iVar7;
        }
        iVar4 = func_0x4008c024(iVar7);
        func_0x4008b4d0(piVar11,iVar7,iVar4 + 1);
        FUN_40184790(param_1,uVar3);
      }
      else {
        cVar2 = *(char *)((int)param_2 + 0xf);
        uVar9 = uVar3;
        while( true ) {
          piVar12 = param_2;
          if (-1 < cVar2) {
            piVar12 = (int *)*param_2;
          }
          iVar7 = func_0x4008ca64(piVar11,piVar12);
          if (iVar7 == 0) break;
          piVar11 = (int *)(iVar7 + iVar4);
          uVar9 = uVar9 + iVar5;
        }
        if (uVar3 != uVar9) {
          uVar3 = 0xe;
          if (-1 < cVar1) {
            uVar3 = param_1[1];
          }
          if ((uVar9 <= uVar3) || (iVar4 = FUN_400f0a5c(param_1,uVar9), iVar4 != 0)) {
            iVar4 = FUN_40184778(param_1);
            while ((-1 < iVar4 + -1 && (iVar4 = FUN_400f14c4(param_1,param_2), -1 < iVar4))) {
              piVar11 = param_1;
              if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
                piVar11 = (int *)*param_1;
              }
              iVar7 = FUN_40184778(param_2);
              iVar10 = (int)piVar11 + iVar7 + iVar4;
              iVar8 = FUN_40184778(param_1);
              func_0x4008b4d0(iVar10 + iVar5,iVar10,iVar8 - (iVar7 + iVar4));
              iVar7 = FUN_40184778(param_1);
              piVar11 = param_1;
              if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
                piVar11 = (int *)*param_1;
              }
              piVar12 = param_3;
              if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
                piVar12 = (int *)*param_3;
              }
              uVar6 = FUN_40184778(param_3);
              func_0x4008b4d0((int)piVar11 + iVar4,piVar12,uVar6);
              FUN_40184790(param_1,iVar5 + iVar7);
              piVar11 = param_1;
              if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
                piVar11 = (int *)*param_1;
              }
              *(undefined1 *)((int)piVar11 + iVar5 + iVar7) = 0;
            }
          }
        }
      }
    }
  }
  return;
}

