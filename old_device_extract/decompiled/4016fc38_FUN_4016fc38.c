// Function : FUN_4016fc38
// Address  : 0x4016fc38
// Size     : 104 bytes


int FUN_4016fc38(int param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int local_30 [12];
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = FUN_40170f24(param_1);
  }
  *param_3 = uVar3;
  pcVar4 = param_2 + 1;
  if (*param_2 == -1) {
    param_3[1] = uVar3;
  }
  else {
    pcVar4 = (char *)FUN_4016fc1c(param_1,*param_2,pcVar4,param_3 + 1);
  }
  cVar1 = *pcVar4;
  *(char *)(param_3 + 5) = cVar1;
  pcVar4 = pcVar4 + 1;
  if (cVar1 == -1) {
    param_3[3] = 0;
  }
  else {
    pcVar4 = (char *)FUN_40186e68(pcVar4,local_30);
    param_3[3] = pcVar4 + local_30[0];
  }
  *(char *)((int)param_3 + 0x15) = *pcVar4;
  iVar2 = FUN_40186e68(pcVar4 + 1,local_30);
  param_3[4] = iVar2 + local_30[0];
  return iVar2;
}

