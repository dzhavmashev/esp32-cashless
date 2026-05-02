// Function : FUN_400fc124
// Address  : 0x400fc124
// Size     : 172 bytes


int FUN_400fc124(int *param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = 0x110b;
  if (param_1[5] != 0) {
    if ((uint)param_1[5] < 2) {
      iVar4 = 0;
      uVar5 = 0;
      for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        uVar3 = 0x7e - *(ushort *)(iVar2 + 0x40);
        if (uVar5 < uVar3) {
          iVar4 = iVar2;
          uVar5 = uVar3;
        }
      }
      iVar2 = 0x1105;
      if ((uVar5 != 0) && (iVar2 = FUN_400fc0d8(param_1), iVar2 == 0)) {
        iVar6 = param_1[1];
        sVar1 = *(short *)(iVar4 + 0x40);
        iVar2 = FUN_400fb4a8(iVar4);
        if ((iVar2 == 0) &&
           (((iVar2 = FUN_400fbff8(iVar4,iVar6), iVar2 == 0 || (iVar2 == 0x1102)) &&
            (iVar2 = FUN_400fb46c(iVar4), iVar2 == 0)))) {
          if (*(short *)(iVar6 + 0x40) == sVar1) {
            FUN_40184bd0(param_1,iVar4);
            FUN_40184bac(param_1 + 3,iVar4);
          }
          else {
            iVar2 = -1;
          }
        }
      }
    }
    else {
      iVar2 = FUN_400fc0d8(param_1);
    }
  }
  return iVar2;
}

