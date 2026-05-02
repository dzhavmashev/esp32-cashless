// Function : FUN_401163c4
// Address  : 0x401163c4
// Size     : 180 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401163c4(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int aiStack_24 [9];
  
  if (7 < *(ushort *)(param_1 + 10)) {
    pcVar4 = *(char **)(param_1 + 4);
    iVar2 = FUN_4011dc60(pcVar4);
    if ((iVar2 == 0) && (iVar2 = FUN_40185484(param_2,param_3), iVar2 != 0)) {
      if (*pcVar4 == '\x11') {
        iVar1 = *(int *)(pcVar4 + 4);
        if (*param_3 == _DAT_3ffc6480) {
          if (iVar1 == 0) {
            if (pcVar4[1] == '\0') {
              pcVar4[1] = '\n';
              memw();
            }
            piVar3 = *(int **)(param_2 + 0xcc);
            if (piVar3 != (int *)0x0) {
              while (piVar3 = (int *)*piVar3, piVar3 != (int *)0x0) {
                memw();
                FUN_40116274(piVar3,pcVar4[1]);
              }
            }
            goto LAB_401163cd;
          }
          memw();
          aiStack_24[0] = iVar1;
          iVar2 = FUN_40185484(param_2,aiStack_24);
          iVar1 = iVar2;
        }
        if (iVar1 != 0) {
          FUN_40116274(iVar2,pcVar4[1]);
        }
      }
      else if ((*pcVar4 == '\x16') && (*(char *)(iVar2 + 9) == '\x01')) {
        *(undefined4 *)(iVar2 + 8) = 0x200;
        memw();
      }
    }
  }
LAB_401163cd:
  FUN_4010bb10(param_1);
  return;
}

