// Function : FUN_40118554
// Address  : 0x40118554
// Size     : 321 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40118554(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  if (0x17 < *(ushort *)(param_1 + 10)) {
    pcVar3 = *(char **)(param_1 + 4);
    if (*pcVar3 == -0x7e) {
      if ((((_DAT_3ffc83e4 == 0x2ff) && (_DAT_3ffc83e8 == 0 && _DAT_3ffc83ec == 0)) &&
          (_DAT_3ffc83f0 == 0x1000000)) &&
         (((*(int *)(pcVar3 + 8) == 0 && (*(int *)(pcVar3 + 0xc) == 0)) &&
          ((*(int *)(pcVar3 + 0x10) == 0 && (*(int *)(pcVar3 + 0x14) == 0)))))) {
        for (piVar2 = *(int **)(param_2 + 0xd0); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          if (((piVar2[1] & 0x8fffU) != 0x1ff) &&
             (((piVar2[1] != 0x2ff || (piVar2[2] != 0)) ||
              ((piVar2[3] != 0 || (piVar2[4] != 0x1000000)))))) {
            FUN_40118498(piVar2,*(undefined2 *)(pcVar3 + 4));
          }
        }
      }
      else {
        iVar1 = FUN_401854d8(param_2,&DAT_3ffc83e4);
        if (iVar1 != 0) {
          FUN_40118498(iVar1,*(undefined2 *)(pcVar3 + 4));
        }
      }
    }
    else if (((*pcVar3 == -0x7d) && (iVar1 = FUN_401854d8(param_2,&DAT_3ffc83e4), iVar1 != 0)) &&
            (*(char *)(iVar1 + 0x19) == '\x01')) {
      *(undefined4 *)(iVar1 + 0x18) = 0x200;
      memw();
    }
  }
  FUN_4010bb10(param_1);
  return;
}

