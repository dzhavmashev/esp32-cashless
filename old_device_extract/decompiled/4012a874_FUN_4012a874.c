// Function : FUN_4012a874
// Address  : 0x4012a874
// Size     : 230 bytes


undefined4 FUN_4012a874(int *param_1,char *param_2,uint param_3,ushort *param_4)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iStack_28;
  int aiStack_24 [9];
  
  iVar6 = 0xb;
  cVar1 = *(char *)(*param_1 + 5);
  if (cVar1 != '\x01') {
    iVar6 = 3;
  }
  uVar5 = iVar6 + 2;
  if (uVar5 <= param_3) {
    cVar2 = *param_2;
    *(char *)(param_4 + 4) = cVar2;
    memw();
    if ((byte)(cVar2 - 0x14U) < 4) {
      *(char *)((int)param_4 + 9) = param_2[1];
      memw();
      *(char *)(param_4 + 5) = param_2[2];
      memw();
      memw();
      FUN_40185918(&iStack_28,aiStack_24,cVar1,(int)param_4 + 9);
      if ((param_1[4] == iStack_28) && (aiStack_24[0] <= (int)(uint)*(byte *)(*param_1 + 1))) {
        pcVar8 = param_2 + 3;
        if (*(char *)(*param_1 + 5) != '\x01') {
          pcVar8 = (char *)param_1[0x1a];
        }
        (*(code *)&SUB_4008b3d0)(param_4,pcVar8,8);
        *(uint *)(param_4 + 10) = uVar5;
        uVar7 = (uint)CONCAT11(param_2[iVar6],(param_2 + iVar6)[1]);
        *(uint *)(param_4 + 0xc) = uVar7;
        *(char **)(param_4 + 6) = param_2;
        *(uint *)(param_4 + 8) = uVar5 + uVar7;
        if (uVar7 != 0) {
          if (*(char *)(*param_1 + 5) != '\x01') {
LAB_4012a955:
            memw();
            return 0;
          }
          uVar3 = (*param_4 & 0xff) << 8 | (uint)(*param_4 >> 8);
          if (uVar5 + uVar7 <= param_3) {
            if (*(ushort *)(param_1 + 0x23) == uVar3) {
              iVar4 = param_1[0x1a];
              param_1[0x1a] = (int)param_4;
              memw();
              iVar6 = FUN_40129a78(param_1);
              param_1[0x1a] = iVar4;
              if (iVar6 == 0) goto LAB_4012a955;
            }
            else if (*(ushort *)(param_1 + 0x23) + 1 == uVar3) {
              return 0xffff9b80;
            }
            memw();
            return 0xffff9900;
          }
        }
      }
    }
  }
  return 0xffff8e00;
}

