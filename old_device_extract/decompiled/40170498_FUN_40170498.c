// Function : FUN_40170498
// Address  : 0x40170498
// Size     : 188 bytes


void FUN_40170498(char param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  param_2[1] = param_3;
  param_2[2] = 0;
  param_2[3] = 0;
  *param_2 = 0;
  iVar3 = param_4 + 4;
  if (param_1 == '\0') {
    *(int **)(param_3 + 0xc) = param_2;
    if (*(int *)(param_4 + 0xc) != param_3) goto LAB_401704d2;
  }
  else {
    *(int **)(param_3 + 8) = param_2;
    if (param_4 != param_3) {
      if (*(int *)(param_4 + 8) == param_3) {
        *(int **)(param_4 + 8) = param_2;
      }
      goto LAB_401704d2;
    }
    *(int **)(param_4 + 4) = param_2;
  }
  *(int **)(param_4 + 0xc) = param_2;
LAB_401704d2:
  do {
    while( true ) {
      piVar1 = param_2;
      if ((*(int **)(param_4 + 4) == param_2) ||
         (piVar2 = (int *)param_2[1], piVar1 = *(int **)(param_4 + 4), *piVar2 != 0)) {
        *piVar1 = 1;
        return;
      }
      piVar1 = (int *)piVar2[1];
      piVar4 = (int *)piVar1[2];
      if (piVar2 != piVar4) break;
      piVar4 = (int *)piVar1[3];
      if ((piVar4 == (int *)0x0) || (*piVar4 != 0)) {
        if ((int *)piVar2[3] == param_2) {
          FUN_40186f58(piVar2,iVar3);
          param_2 = piVar2;
        }
        *(undefined4 *)param_2[1] = 1;
        *piVar1 = 0;
        FUN_40186f88(piVar1,iVar3);
      }
      else {
LAB_4017051e:
        *piVar2 = 1;
        *piVar4 = 1;
        *piVar1 = 0;
        param_2 = piVar1;
      }
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 == 0)) goto LAB_4017051e;
    if ((int *)piVar2[2] == param_2) {
      FUN_40186f88(piVar2,iVar3);
      param_2 = piVar2;
    }
    *(undefined4 *)param_2[1] = 1;
    *piVar1 = 0;
    FUN_40186f58(piVar1,iVar3);
  } while( true );
}

