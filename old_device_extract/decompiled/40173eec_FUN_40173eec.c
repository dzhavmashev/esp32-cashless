// Function : FUN_40173eec
// Address  : 0x40173eec
// Size     : 249 bytes


int FUN_40173eec(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined4 local_30 [12];
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[6] == 0)) {
    (*(code *)&SUB_4008a890)(param_1);
  }
  if (param_2 == (int *)0x3ff96498) {
    param_2 = (int *)param_1[1];
  }
  else if (param_2 == (int *)0x3ff96478) {
    param_2 = (int *)param_1[2];
  }
  else if (param_2 == (int *)0x3ff96458) {
    param_2 = (int *)param_1[3];
  }
  FUN_4018560c(1,local_30);
  if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
    (*(code *)&SUB_40086504)(param_2[0x16]);
  }
  if ((code *)param_2[0xb] == (code *)0x0) {
    *param_1 = 0x1d;
LAB_40173f83:
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      (*(code *)&SUB_40086534)(param_2[0x16]);
    }
    FUN_4018560c(local_30[0],local_30);
    iVar2 = -1;
  }
  else {
    uVar1 = *(ushort *)(param_2 + 3);
    if (((((uVar1 & 0xc) == 8) && (*param_2 != 0)) && (0 < *param_2 - param_2[4])) &&
       ((uVar1 & 0x100) != 0)) {
      uVar4 = 2;
      uVar3 = 0;
LAB_40173f77:
      iVar2 = (*(code *)param_2[0xb])(param_1,param_2[8],uVar3,uVar4);
      if (iVar2 == -1) goto LAB_40173f83;
    }
    else {
      uVar3 = uVar1 & 0x1000;
      if ((uVar1 & 0x1000) == 0) {
        uVar4 = 1;
        goto LAB_40173f77;
      }
      iVar2 = param_2[0x15];
    }
    uVar1 = *(ushort *)(param_2 + 3);
    if ((uVar1 & 4) == 0) {
      if (((uVar1 & 8) != 0) && (*param_2 != 0)) {
        iVar2 = iVar2 + (*param_2 - param_2[4]);
      }
    }
    else {
      iVar2 = iVar2 - param_2[1];
      if (param_2[0xd] != 0) {
        iVar2 = iVar2 - param_2[0x10];
      }
    }
    if (((param_2[0x19] & 1U) == 0) && ((uVar1 & 0x200) == 0)) {
      (*(code *)&SUB_40086534)(param_2[0x16]);
    }
    FUN_4018560c(local_30[0],local_30);
  }
  return iVar2;
}

