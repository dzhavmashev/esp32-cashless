// Function : FUN_400f17ac
// Address  : 0x400f17ac
// Size     : 34 bytes


void FUN_400f17ac(char *param_1)

{
  char cVar1;
  
  if (((param_1[0xf] & 0x80U) != 0) || (param_1 = *(char **)param_1, param_1 != (char *)0x0)) {
    for (; *param_1 != '\0'; param_1 = param_1 + 1) {
      cVar1 = func_0x4008cd54();
      *param_1 = cVar1;
    }
  }
  return;
}

