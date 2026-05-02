// Function : FUN_40184884
// Address  : 0x40184884
// Size     : 72 bytes


uint FUN_40184884(uint *param_1,char *param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 == (uint *)0x0) || (param_2 == (char *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else if (*param_2 == '\0') {
    uVar1 = 0xffffffff;
    if (param_2[1] != '\0') {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
    if (param_2[1] != '\0') {
      uVar3 = param_1[8];
      uVar1 = *param_1;
      uVar2 = (uVar1 < uVar3) * uVar1 + (uVar1 >= uVar3) * uVar3;
      if (param_3 != '\0') {
        uVar2 = (uVar1 < uVar3) * uVar3 + (uVar1 >= uVar3) * uVar1;
      }
      uVar1 = (uint)(uVar1 != uVar2);
    }
  }
  return uVar1;
}

