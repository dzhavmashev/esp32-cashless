// Function : FUN_4010d5f0
// Address  : 0x4010d5f0
// Size     : 263 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010d5f0(int *param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    bVar1 = true;
    if ((char)param_1[5] == '\x06') {
      if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)) {
        bVar1 = false;
      }
    }
    else {
      bVar1 = *param_1 != 0;
    }
    if (bVar1) {
      FUN_4010d578(param_1,_DAT_3ffc840c);
      FUN_4010d578(param_1,_DAT_3ffc8410);
      if (param_2 != (int *)0x0) {
        bVar1 = true;
        if ((char)param_2[5] == '\x06') {
          if (((*param_2 == 0) && (param_2[1] == 0)) && ((param_2[2] == 0 && (param_2[3] == 0)))) {
            bVar1 = false;
          }
        }
        else {
          bVar1 = *param_2 != 0;
        }
        piVar2 = _DAT_3ffc841c;
        if (bVar1) {
          while (piVar2 != (int *)0x0) {
            if ((char)param_1[5] == (char)piVar2[5]) {
              if ((char)param_1[5] == '\x06') {
                bVar1 = false;
                if (((*param_1 == *piVar2) && (piVar2[1] == param_1[1])) &&
                   ((piVar2[2] == param_1[2] && (piVar2[3] == param_1[3])))) {
                  bVar1 = (char)piVar2[4] == (char)param_1[4];
                }
              }
              else {
                bVar1 = *param_1 == *piVar2;
              }
              if (bVar1) {
                iVar3 = param_2[5];
                *(char *)(piVar2 + 5) = (char)iVar3;
                memw();
                if ((char)iVar3 == '\x06') {
                  *piVar2 = *param_2;
                  piVar2[1] = param_2[1];
                  piVar2[2] = param_2[2];
                  piVar2[3] = param_2[3];
                  *(char *)(piVar2 + 4) = (char)param_2[4];
                  memw();
                }
                else {
                  iVar3 = *param_2;
                  piVar2[3] = 0;
                  *piVar2 = iVar3;
                  piVar2[2] = 0;
                  piVar2[1] = 0;
                  *(undefined1 *)(piVar2 + 4) = 0;
                  memw();
                  memw();
                }
              }
            }
            memw();
            piVar2 = (int *)piVar2[0xd];
          }
        }
      }
    }
  }
  return;
}

