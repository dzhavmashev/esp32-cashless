// Function : FUN_40113b68
// Address  : 0x40113b68
// Size     : 180 bytes


undefined1 FUN_40113b68(uint *param_1,int param_2,int param_3,undefined2 param_4,int param_5)

{
  undefined1 uVar1;
  uint *puVar2;
  uint uVar3;
  
  if ((param_2 == 0 || (param_3 == 0 || param_5 == 0)) || (param_1 == (uint *)0x0)) {
    return 0xf0;
  }
  if (((char)param_1[5] != '.') && ((char)param_1[5] != *(char *)(param_3 + 0x14))) {
    return 0xfa;
  }
  uVar3 = *param_1;
  puVar2 = param_1;
  if (*(char *)(param_3 + 0x14) != '\x06') {
    if ((uVar3 == 0) || ((uVar3 & 0xf0) == 0xe0)) {
      puVar2 = (uint *)(param_5 + 4);
    }
    else if (*(uint *)(param_5 + 4) != uVar3) {
      return 0xfc;
    }
    goto LAB_40113bc4;
  }
  if (uVar3 == 0) {
    if (((param_1[1] == 0) && (param_1[2] == 0)) && (param_1[3] == 0)) {
LAB_40113be6:
      puVar2 = (uint *)FUN_401174f8(param_5,param_3);
      if (puVar2 == (uint *)0x0) {
        return 0xfc;
      }
      goto LAB_40113bc4;
    }
  }
  else if ((uVar3 & 0xff) == 0xff) goto LAB_40113be6;
  uVar3 = FUN_4010b8c0(param_5,param_1);
  if ((uVar3 & 0x80) != 0) {
    return 0xfc;
  }
LAB_40113bc4:
  uVar1 = FUN_4011397c(param_1,param_2,param_3,param_4,param_5,puVar2);
  return uVar1;
}

