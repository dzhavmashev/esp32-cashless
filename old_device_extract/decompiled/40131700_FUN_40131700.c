// Function : FUN_40131700
// Address  : 0x40131700
// Size     : 57 bytes


undefined8 FUN_40131700(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_40131574(param_1,1);
  if (iVar2 == 0) {
    (*(code *)&SUB_4008b530)(param_1[2],0,param_1[1] << 2);
    iVar3 = param_2;
    if (param_2 < 1) {
      iVar3 = -param_2;
    }
    *(int *)param_1[2] = iVar3;
    bVar1 = param_2 < 0;
    param_2 = 1;
    if (bVar1) {
      param_2 = -1;
    }
    *param_1 = param_2;
  }
  memw();
  return CONCAT44(param_2,iVar2);
}

