// Function : FUN_40113f70
// Address  : 0x40113f70
// Size     : 242 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40113f70(int *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    bVar2 = true;
    if ((char)param_1[5] == '\x06') {
      if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)) {
        bVar2 = false;
      }
    }
    else {
      bVar2 = *param_1 != 0;
    }
    bVar1 = true;
    if ((param_2 != (int *)0x0) && (bVar2)) {
      if ((char)param_2[5] == '\x06') {
        if (((*param_2 == 0) && (param_2[1] == 0)) && ((param_2[2] == 0 && (param_2[3] == 0)))) {
          bVar1 = false;
        }
      }
      else {
        bVar1 = *param_2 != 0;
      }
      piVar3 = _DAT_3ffc8424;
      if (bVar1) {
        while (piVar3 != (int *)0x0) {
          if ((char)param_1[5] == (char)piVar3[5]) {
            if ((char)param_1[5] == '\x06') {
              bVar2 = false;
              if ((((*param_1 == *piVar3) && (piVar3[1] == param_1[1])) && (piVar3[2] == param_1[2])
                  ) && (piVar3[3] == param_1[3])) {
                bVar2 = (char)piVar3[4] == (char)param_1[4];
              }
            }
            else {
              bVar2 = *param_1 == *piVar3;
            }
            if (bVar2) {
              iVar4 = param_2[5];
              *(char *)(piVar3 + 5) = (char)iVar4;
              memw();
              if ((char)iVar4 == '\x06') {
                *piVar3 = *param_2;
                piVar3[1] = param_2[1];
                piVar3[2] = param_2[2];
                piVar3[3] = param_2[3];
                *(char *)(piVar3 + 4) = (char)param_2[4];
                memw();
              }
              else {
                iVar4 = *param_2;
                piVar3[3] = 0;
                *piVar3 = iVar4;
                piVar3[2] = 0;
                piVar3[1] = 0;
                *(undefined1 *)(piVar3 + 4) = 0;
                memw();
                memw();
              }
            }
          }
          memw();
          piVar3 = (int *)piVar3[0xd];
        }
      }
    }
  }
  return;
}

