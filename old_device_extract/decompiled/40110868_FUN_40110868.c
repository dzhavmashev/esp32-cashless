// Function : FUN_40110868
// Address  : 0x40110868
// Size     : 281 bytes


undefined4 FUN_40110868(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  uVar5 = param_2 & 0xff;
  if ((param_2 & 3) != 0) goto LAB_40110888;
  pcVar9 = "len > 0";
  uVar8 = 0x412;
  while( true ) {
    while( true ) {
      (*(code *)&SUB_40094c54)("lid pcb",uVar8,"_output",pcVar9);
LAB_40110888:
      if (param_1 != 0) break;
      pcVar9 = "es API)";
      uVar8 = 0x413;
    }
    uVar2 = uVar5 >> 1 & 1;
    uVar6 = uVar2 << 2;
    iVar3 = FUN_4010bbc4(0x4a,uVar6,0x280);
    if (iVar3 == 0) break;
    if (*(ushort *)(iVar3 + 10) < uVar6) {
      pcVar9 = "lid pcb";
      uVar8 = 0x43a;
    }
    else {
      iVar3 = FUN_4010ffc8(param_1,iVar3,uVar5,*(undefined4 *)(param_1 + 0x88),uVar2);
      if (iVar3 == 0) break;
      if ((*(uint *)(iVar3 + 0xc) & 3) == 0) {
        if (*(short *)(iVar3 + 8) == 0) {
          piVar7 = *(int **)(param_1 + 0x98);
          if (*(int **)(param_1 + 0x98) == (int *)0x0) {
            *(int *)(param_1 + 0x98) = iVar3;
          }
          else {
            do {
              piVar4 = piVar7;
              piVar7 = (int *)*piVar4;
            } while (piVar7 != (int *)0x0);
            *piVar4 = iVar3;
            memw();
          }
          *(undefined2 *)(param_1 + 0x94) = 0;
          memw();
          *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
          if ((uVar5 & 1) != 0) {
            *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 0x20;
            memw();
          }
          memw();
          sVar1 = FUN_40185360(*(undefined4 *)(iVar3 + 4));
          sVar1 = sVar1 + *(short *)(param_1 + 0x92);
          *(short *)(param_1 + 0x92) = sVar1;
          memw();
          uVar8 = 0;
          if (((sVar1 == 0) || (uVar8 = 0, *(int *)(param_1 + 0x9c) != 0)) ||
             (uVar8 = 0, *(int *)(param_1 + 0x98) != 0)) goto LAB_401108be;
          pcVar9 = " length";
          uVar8 = 0x466;
          memw();
          uVar5 = 0;
          param_1 = 0;
        }
        else {
          pcVar9 = "aligned";
          uVar8 = 0x443;
        }
      }
      else {
        pcVar9 = " optlen";
        uVar8 = 0x442;
      }
    }
  }
  *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 0x80;
  memw();
  uVar8 = 0xff;
LAB_401108be:
  memw();
  return uVar8;
}

